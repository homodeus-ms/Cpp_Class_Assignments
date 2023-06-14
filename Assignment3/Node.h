#pragma once

namespace assignment3
{
	template <typename T>
	struct Node
	{
		Node* Prev;
		T Value;
		Node* Next;
	};
}