#include "scenes/testscene.hpp"

void TestScene::Initialize(Engine* eng)
{
	Entity player = eng->CreateEntity();
	Entity player2 = eng->CreateEntity();
	player.AddComponent<CPosition>({ 300, 53 });
	player.AddComponent<double>(3.346);
	player2.AddComponent<CPosition>({ 300, 346 });
	player2.AddComponent<double>(43.546);
	m_entities.push_back(player);
	m_entities.push_back(player2);
	std::cout << player.GetComponent<CPosition>().x;
}

void TestScene::OnSceneDestroy(Engine* eng)
{
}

void TestScene::Update(Engine* eng)
{
	std::cout << "Player 1: " << m_entities[0].GetComponent<CPosition>().x << ", " << m_entities[0].GetComponent<CPosition>().y << "\n";
	std::cout << "Player 2: " << m_entities[1].GetComponent<CPosition>().x << ", " << m_entities[1].GetComponent<CPosition>().y << "\n";
}
