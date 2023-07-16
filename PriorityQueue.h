#include <vector>

class PriorityQueue
{
private:
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0; // Priority Queue is Empty.
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return 0; // Pq is empty
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int pi = 0;
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;

        while ( lci < pq.size())
        {
            int minIndex = pi;
            if (pq[minIndex] > pq[lci])
            {
                minIndex = lci;
            }
            else if (rci < pq.size() && pq[minIndex] > pq[rci])
            {
                minIndex = rci;
            }

            if(minIndex == pi)
            {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[pi];
            pq[pi] = temp;

            lci = 2 * pi + 1;
            rci = 2 * pi + 2;
        }

        return ans;
    }
};
