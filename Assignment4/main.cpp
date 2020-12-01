#include <cassert>
#include "TreeNode.h"
#include "BinarySearchTree.h"

using namespace assignment4;

void BinarySearchTreeTest();

int main()
{
    BinarySearchTreeTest();

	return 0;
}

void BinarySearchTreeTest()
{
	assignment4::BinarySearchTree<float> tree;
	std::vector<float> v1;
	//빈트리에 대한 테스트
	assert(tree.GetRootNode().lock() == nullptr);
	assert(tree.Delete(1.f) == false);
	assert(tree.Search(1.f) == false);

	//루트 노드 하나만 있을 때 테스트
	tree.Insert(std::make_unique<float>(1.2f));
	assert(*tree.GetRootNode().lock()->Data == 1.2f);
	assert(tree.Search(1.2f) == true);

	v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 1);
	assert(v1[0] = 1.2f);
	assert(tree.Delete(1.3f) == false);
	assert(tree.Delete(1.2f) == true);
	assert(tree.GetRootNode().lock() == nullptr);

	//그냥 여러 테스트...
	tree.Insert(std::make_unique<float>(50.f));
	tree.Insert(std::make_unique<float>(25.f));
	tree.Insert(std::make_unique<float>(75.f));
	tree.Insert(std::make_unique<float>(12.5f));
	tree.Insert(std::make_unique<float>(37.5f));
	tree.Insert(std::make_unique<float>(38.f));
	tree.Insert(std::make_unique<float>(62.5f));
	tree.Insert(std::make_unique<float>(87.5f));
	tree.Insert(std::make_unique<float>(6.f));
	tree.Insert(std::make_unique<float>(3.f));
	tree.Insert(std::make_unique<float>(30.f));
	tree.Insert(std::make_unique<float>(31.f));
	tree.Insert(std::make_unique<float>(32.f));
	tree.Insert(std::make_unique<float>(88.f));
	tree.Insert(std::make_unique<float>(89.f));

	v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 15);
	assert(v1[0] == 3.f);
	assert(v1[1] == 6.f);
	assert(v1[2] == 12.5f);
	assert(v1[3] == 25.f);
	assert(v1[4] == 30.f);
	assert(v1[5] == 31.f);
	assert(v1[6] == 32.f);
	assert(v1[7] == 37.5f);
	assert(v1[8] == 38.f);
	assert(v1[9] == 50.f);
	assert(v1[10] == 62.5f);
	assert(v1[11] == 75.f);
	assert(v1[12] == 87.5f);
	assert(v1[13] == 88.f);
	assert(v1[14] == 89.f);

	assert(tree.Search(34.f) == false);
	assert(tree.Search(62.5f) == true);

	assert(tree.Delete(34.f) == false);
	assert(tree.Delete(12.5f) == true);
	assert(tree.Delete(37.5f) == true);
	assert(tree.Delete(25.f) == true);
	assert(tree.Delete(25.f) == false);
	assert(tree.Delete(87.5f) == true);

	assert(tree.Delete(50.f) == true); //루트노드 삭제 테스트
	assert(tree.GetRootNode().lock() != nullptr);
	assert(*tree.GetRootNode().lock()->Data == 38.f);



	assert(tree.Search(37.5f) == false);

	v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 10);
	assert(v1[0] == 3.f);
	assert(v1[1] == 6.f);
	assert(v1[2] == 30.f);
	assert(v1[3] == 31.f);
	assert(v1[4] == 32.f);
	assert(v1[5] == 38.f);
	assert(v1[6] == 62.5f);
	assert(v1[7] == 75.f);
	assert(v1[8] == 88.f);
	assert(v1[9] == 89.f);

	//재배치된 노드 삭제 테스트
	assert(tree.Delete(32.f) == true);
	assert(tree.Delete(6.f) == true);
	assert(tree.Delete(88.f) == true);

	v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 7);
	assert(v1[0] == 3.f);
	assert(v1[1] == 30.f);
	assert(v1[2] == 31.f);
	assert(v1[3] == 38.f);
	assert(v1[4] == 62.5f);
	assert(v1[5] == 75.f);
	assert(v1[6] == 89.f);
}