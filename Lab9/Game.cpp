#include "Game.h"

namespace lab9
{
	Game::Game(unsigned int seed, unsigned int poolSize)
		: mObjectPool(poolSize)
	{
		srand(seed);
	}

	Game::~Game()
	{
		mActiveGameObjects.clear();
	}

	void Game::Spawn()
	{
		std::unique_ptr<IceCube> iceCube = mObjectPool.Get();
		iceCube->Initialize(rand() % MAX_FRAME_COUNT_TO_LIVE + 1);
		mActiveGameObjects.push_back(iceCube);
	}

	void Game::Update()
	{
		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end();)
		{
			std::unique_ptr<IceCube> iceCube = std::move(*it);
			iceCube->Animate();

			if (!iceCube->IsActive())
			{
				it = mActiveGameObjects.erase(it);
				mObjectPool.Return(iceCube);
				continue;
			}

			++it;
		}
	}

	const std::vector<std::unique_ptr<IceCube>> Game::GetActiveGameObjects() const
	{
		return mActiveGameObjects;
	}

	ObjectPool<IceCube>& Game::GetObjectPool()
	{
		return mObjectPool;
	}
}