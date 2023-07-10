#include "Game.h"

namespace lab9
{
	Game::Game(unsigned int seed, unsigned int poolSize)
		: mRandom(seed)
	{
		mPoolPtr = new ObjectPool<IceCube>(poolSize);
	}

	Game::~Game()
	{
		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end(); ++it)
		{
			delete (*it);
		}

		delete mPoolPtr;

		mActiveGameObjects.clear();
	}

	void Game::Spawn()
	{
		IceCube* iceCube = mPoolPtr->Get();
		iceCube->Initialize(mRandom.GetNext() % MAX_FRAME_COUNT_TO_LIVE + 1);
		mActiveGameObjects.push_back(iceCube);
	}

	void Game::Update()
	{
		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end();)
		{
			IceCube* iceCube = *it;
			iceCube->Animate();

			if (!iceCube->IsActive())
			{
				it = mActiveGameObjects.erase(it);
				mPoolPtr->Return(iceCube);
				continue;
			}

			++it;
		}
	}

	const std::vector<IceCube*>& Game::GetActiveGameObjects() const
	{
		return mActiveGameObjects;
	}

	ObjectPool<IceCube>& Game::GetObjectPool() const
	{
		return *mPoolPtr;
	}
}