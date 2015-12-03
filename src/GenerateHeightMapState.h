#pragma once
#include <SFML/Graphics.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <math.h>
#include <random>

#include "State.h"
#include "StateManager.h"

//#include "GenerateRoadNetworkState.h"

#include "Heightmap.h"
#include "HeightMapGenerator.h"

#include "HMMP_Volcanic.h"
#include "HMMP_Erosion.h"
#include "HMMP_SmoothStretch.h"
#include "HMMP_LibNoise.h"

class CGenerateHeightMapState :
	public CState
{
private:
	CHeightMap*								m_pMap;
	CHeightMapGenerator*					m_pMapGenerator;
	std::vector<std::vector<sf::Vector2f>>	m_contours;

    sf::RenderWindow*                       m_wndw;
	sf::RectangleShape						m_shp;
	sf::RenderTexture						m_lines_renderTexture;
	sf::RenderTexture						m_map_renderTexture;
	sf::Sprite								m_lines_Sprite;
	sf::Sprite								m_map_Sprite;
	int 									m_seed;

	bool									underlay = true;
	bool									was_pressed = false;
public:
	CGenerateHeightMapState();
	~CGenerateHeightMapState();

    void setHeightMap (CHeightMap* map) {m_pMap = map;}
    void setRenderWindow (sf::RenderWindow* wndw) {m_wndw = wndw;}

	void on_Enter();
	bool on_Update(sf::Time dt);
    void on_Render();
	void on_Exit();
};

