/*
 * TextureManager.h
 *
 *  Created on: Nov 2, 2009
 *      Author: juanmarcus
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include "ibi.h"
#include <vector>
#include "TextureLoader.h"

namespace ibi
{

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void registerTextureLoader(String type,
			TextureLoaderFactory* textureLoaderFactory);

	void loadPlugin(String filename);

	TextureLoader* getLoader(String type);

	Texture* load(TextureLoadingInfo& info);
private:
	std::map<String, TextureLoaderFactory*> factories;
	std::vector<void*> loadedPlugins;
};

} // namespace ibi

#endif /* TEXTUREMANAGER_H_ */