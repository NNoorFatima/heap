#include <iostream>
using namespace std;
#include <queue>

//applications
//heapsort
//priority queue ==> useful in graphs algo such as dijkstra's shortest path and prim minimum spanning tree

template <typename T>
class minHeap
{
public:
	int capacity;
	int cur_index;
	T* arr;
	minHeap()
	{
		
		capacity = 10;
		arr = new T[capacity];
		cur_index = 0;
	}
	minHeap(int c)
	{
		capacity = c;
		cur_index = 0;
		arr = new T[capacity];
		
	}
	T parent(int index)
	{
		return (index-1)/2;
	}
	T leftchild(int index)
	{
		return (2 * index + 1);
	}
	T rightchild(int index)
	{
		return (2 * index + 2);
	}
	T minimum()
	{
		return arr[0];
	}
	void insert(T value)
	{
		if (cur_index == 0)
		{
			arr[cur_index] = value;
			cur_index++;
		}
		else
		{
			if (cur_index > capacity)
				cout << "sorry can't insert\n";
			else
			{
				arr[cur_index] = value;
				
				int i = cur_index;
				cur_index++;
				//check if follows the rule of min heap
				while (i != 0 && arr[parent(i)] > arr[i])
				{
					T temp = arr[i];
					arr[i] = arr[parent(i)];
					arr[parent(i)] = temp;
					i = parent(i);

				}
			}
		}
	}
	void print()
	{
		
		int i = 0;
		while (i < cur_index)
		{
			cout << arr[i] << " ";
			i++;
		}
		cout << endl;

	}
	void heapify(int i)
	{
		/*It takes the index of a heap node as a parameter.
		Let ‘RIGHT’and ‘LEFT’ be the indices of its rightand left children.
		Let i be the index of the minimum - key node among these three nodes.
		If i is not equal to the node's index passed as a parameter, swap with the node at index i and recursively call the heapify() function with i passed as a parameter.*/

		int left_node = leftchild(i);	//index of left child
		int right_node = rightchild(i);	//index of right child 
		int smallest = i;	//parent in this case 
		if (left_node < cur_index && arr[left_node] < arr[i])	 
			smallest = left_node;								
		if (right_node < cur_index && arr[right_node] < arr[smallest])	
			smallest = right_node;	
		if (smallest != i)	//swap 
		{
			T temp = arr[i];
			arr[i] = arr[smallest];
			arr[smallest] = temp;
			heapify(smallest);
		}
	}
	void deleteMin()	//always deletes the root 
	{
		if (cur_index == 0)//noot fsitim shaihd razadssdsdg
			return;		//no values added to the heap yet
		else
		{
			arr[0] = arr[cur_index - 1];
			cur_index--;
			heapify(0);
		}
	}
};

int main()
{
	minHeap<int> a;
	a.insert(2);
	a.insert(4);
	a.insert(1);
	a.insert(6);
	a.insert(0);
	a.print();
	cout<<a.minimum()<<endl;
	a.deleteMin();
	cout << a.minimum() << endl;
	a.print();
	a.deleteMin();
	a.insert(0);
	cout << a.minimum() << endl;
	a.print();
	a.insert(10);
	a.insert(20);
	a.print();
}