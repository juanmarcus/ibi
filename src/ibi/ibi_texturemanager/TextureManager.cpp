/*
 * TextureManager.cpp
 *
 *  Created on: Nov 2, 2009
 *      Author: juanmarcus
 */

#include "TextureManager.h"
#include "ibi_error/Exception.h"
#include <dlfcn.h>

namespace ibi
{

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	std::vector<void*>::iterator it = loadedPlugins.begin();
	std::vector<void*>::iterator itEnd = loadedPlugins.end();

	for (; it != itEnd; ++it)
	{
		dlclose(*it);
	}
}

void TextureManager::registerTextureLoader(String type,
		TextureLoaderFactory* textureLoaderFactory)
{
	factories[type] = textureLoaderFactory;
}

void TextureManager::loadPlugin(String filename)
{
	void* phandle = dlopen(filename.c_str(), RTLD_NOW);
	if (!phandle)
	{
		throw Exception("Problem loading plugin.");
	}

	// load the entry point
	typedef void (*registerPlugin_t)(TextureManager&);

	// reset errors
	dlerror();
	registerPlugin_t registerPlugin = (registerPlugin_t) dlsym(phandle,
			"registerPlugin");
	const char *dlsym_error = dlerror();
	if (dlsym_error)
	{
		throw Exception("Problem loading entry point.");
		dlclose(phandle);
	}

	registerPlugin(*this);
}

TextureLoader* TextureManager::getLoader(String type)
{
	if (factories.count(type) == 0)
	{
		throw Exception("Problem finding loader for type.");
	}
	else
	{
		return factories[type]->create();
	}
}

Texture* TextureManager::load(TextureLoadingInfo& info)
{
	if (info.texture_type == "")
	{
		throw Exception("Texture type not specified.");
	}
	TextureLoader* loader = getLoader(info.texture_type);
	Texture* t = loader->load(info);
	delete loader;
	return t;
}

} // namespace ibi
