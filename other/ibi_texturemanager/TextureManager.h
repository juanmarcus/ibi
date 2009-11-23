/*
 * TextureManager.h
 *
 *  Created on: Nov 2, 2009
 *      Author: juanmarcus
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include "ibi_internal.h"
#include <vector>
#include "TextureLoader.h"

namespace ibi
{

class TextureManager
{
protected:
	TextureManager();
public:
	static TextureManager* getInstance();

	~TextureManager();

	void registerTextureLoader(String type,
			TextureLoaderFactory* textureLoaderFactory);

	void loadPlugin(String filename);

	Texture* load(TextureLoadingInfo& info);
private:
	std::map<String, TextureLoader*> loaders;
	std::vector<void*> loadedPlugins;

	static TextureManager* instance;
};

} // namespace ibi

#endif /* TEXTUREMANAGER_H_ */
