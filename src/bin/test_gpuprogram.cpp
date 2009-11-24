/*
 * test_gpuprogram.cpp
 *
 *  Created on: Nov 4, 2009
 *      Author: juanmarcus
 */

#include "ibi_gl/ibi_gl.h"
#include <QtGui/QApplication>
#include <iostream>
#include "ibi_qt/ibiQFunctorGLViewer.h"
#include "ibi_gl/Texture.h"
#include "ibi_gpuprogrammanager/GPUProgramManager.h"
#include "ibi_test_utils/TestScene.h"

using namespace std;
using namespace ibi;

Texture* t = 0;
VertexProgram* vertex_program;
FragmentProgram* fragment_program;

struct draw
{
	void operator()(ibiQGLViewer* widget)
	{
		vertex_program->enable();
		fragment_program->enable();

		TestScene::draw();

		vertex_program->disable();
		fragment_program->disable();
	}
};

struct init
{
	GPUProgramManager shaderManager;

	void operator()(ibiQGLViewer* widget)
	{

		shaderManager.init();

		vertex_program = shaderManager.loadVertexProgram("Shaders/Phong.cg",
				"MainVS");
		fragment_program = shaderManager.loadFragmentProgram(
				"Shaders/Phong.cg", "MainPS");

		widget->setSceneRadius(4.0);
		widget->showEntireScene();

		//		TextureLoadingInfo tinfo;
		//		tinfo.texture_type = "qt";
		//		tinfo.target = GL_TEXTURE_2D;
		//		tinfo.options["filename"] = String("data/image.png");
		//
		//		TextureManager manager;
		//		manager.loadPlugin("build/lib/libtexture_loader_qt.so");
		//
		//		t = manager.load(tinfo);

	}
};

InitializeFunctor initer = init();
DrawFunctor drawer = draw();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	QApplication app(argc, argv);

	ibiQFunctorGLViewer w(initer, drawer);

	w.showMaximized();

	return app.exec();
}
