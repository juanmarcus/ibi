/*
 * TextureManager.cpp
 *
 *  Created on: Nov 2, 2009
 *      Author: juanmarcus
 */

#include "TextureManager.h"
#include "ibi_error/Exception.h"
#include <dlfcn.h>

BEGIN_NAMESPACE_IBI
{

TextureManager* TextureManager::instance = 0;

TextureManager* TextureManager::getInstance()
{
	if (!instance)
	{
		instance = new TextureManager();
	}
	return instance;
}

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
	loaders[type] = textureLoaderFactory->create();
}

void TextureManager::loadPlugin(String filename)
{
	void* phandle = dlopen(filename.c_str(), RTLD_NOW);
	if (!phandle)
	{
		throw Exception("TextureManager.cpp", "Problem loading plugin.",
				"File not found: " + filename);
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
		throw Exception("TextureManager.cpp", "Problem loading entry point.",
				"Can't find a function called 'registerPlugin' in the library.");
		dlclose(phandle);
	}

	registerPlugin(*this);
}

Texture* TextureManager::load(TextureLoadingInfo& info)
{
	if (info.texture_type == "")
	{
		throw Exception("TextureManager.cpp", "Texture type not specified.");
	}

	if (loaders.count(info.texture_type) == 0)
	{
		throw Exception("TextureManager.cpp",
				"Problem finding loader for type.", "Type: "
						+ info.texture_type);
	}

	// Get loader
	TextureLoader* loader = loaders[info.texture_type];

	// Initialize texture
	Texture* texture = new Texture();
	texture->setTarget(info.target);
	texture->init();

	// Call plugin loader
	loader->load(info, texture);

	// Disable texture to avoid problems
	texture->disable();

	return texture;
}

END_NAMESPACE_IBI
