#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "Quad.h"
#include "TexturedQuad.h"


#define CAMERA_WIDTH 640
#define CAMERA_HEIGHT 480


// Scene contains all the entities of our game.
// It is responsible for updating and render them.


class Scene
{

public:
	Scene();
	~Scene();

	void init();
	void update(int deltaTime);
	void render();
	void manageXPos(int x);

private:
	void initShaders();

private:
	Quad *quad;
	Texture texs[2];
	TexturedQuad *texQuad[3];
	ShaderProgram simpleProgram, texProgram;
	float currentTime;
	glm::mat4 projection;
	float x_pos = 0;

};


#endif // _SCENE_INCLUDE

