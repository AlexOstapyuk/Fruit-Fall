#include "pch.h"

#include "OpenGLRenderer.h"
#include "PowerWindow.h"
#include "glad/glad.h"


namespace ow {
	
	OpenGLRenderer::OpenGLRenderer()
	{
		//start GLAD

		//create OpenGL objects

		glGenVertexArrays(1, &mVAO);
		glBindVertexArray(mVAO);


		glGenBuffers(1, &mVBO);
		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);


		glGenBuffers(1, &mEBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
		
	}

	void OpenGLRenderer::Draw(Image& file, int xCoord, int yCoord)
	{
		float vertices[] = {
			xCoord,						yCoord,							0.0f, 0.0f, 
			xCoord,						yCoord + file.getHeight(),		0.0f, 1.0f, 
			xCoord + file.getWidth(),	yCoord + file.getHeight(),		1.0f, 1.0f, 
			xCoord + file.getWidth(),	yCoord,							1.0f, 0.0f 

		};

		unsigned int indices[]{
			0,1,2, //first triangle
			0,2,3 //second triangle
		};

		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		mDefaultShaders.Bind();
		mDefaultShaders.setIntUniform("ScreenDim", 
			{ PowerWindow::GetWindow()->getWidth(), PowerWindow::GetWindow()->getHeight() });
		glBindVertexArray(mVAO);
		file.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	
	void OpenGLRenderer::Draw(Image& file, int xCoord, int yCoord, Shaders& shader)
	{
	}
	void OpenGLRenderer::ClearScreen()
	{
	}
}