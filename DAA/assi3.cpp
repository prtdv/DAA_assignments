//Write a program for Minimum Spanning Tree using Greedy approach ( Prim's Algorithm )
#include<iostream>
#define MAX 100
#define INFI 9999

using namespace std;

class graph
{
	int cost[MAX][MAX];
	int city;
	
	public:
		graph();
		void create();
		void display();
		void prims();
};

graph::graph()
{
	city = 0;
	cout << "\nEnter the number of cities : ";
	cin >> city;
	for(int i = 0; i < city; i++)
	{
		for(int j = 0; j < city; j++)
		{
			cost[i][j] = INFI;
		}
	}
}

void graph::create()
{
	for(int i = 0; i < city; i++)
	{
		for(int j = i+1; j < city; j++)
		{
			char ch;
			cout << "\nConnection between "<< i <<" and "<< j <<" (Y/N) : ";
			cin >> ch;
			if(ch == 'y' || ch == 'Y')
			{
				cout << "Enter the cost : ";
				cin >> cost[i][j];
				cost[j][i] = cost[i][j];
			}
		}
	}
}

void graph::display()
{
	cout << "Cost adjcency matrix : \n";
	for(int i = 0; i < city; i++)
	{
        for(int j = 0; j < city; j++)
        {
            if(cost[i][j] == INFI)
                cout << "INFI\t";
            else
                cout << cost[i][j] << "\t";
        }
        cout << endl;
    }
}

void graph::prims()
{
    int minCost = 0;
    bool selected[MAX] = {false};
    selected[0] = true;
    
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    
    for(int edges = 0; edges < city-1; edges++)
    {
        int min = INFI, x = -1, y = -1;
        
        for(int i = 0; i < city; i++)
        {
            if(selected[i])
            {
                for(int j = 0; j < city; j++)
                {
                    if(!selected[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        
        if(x != -1 && y != -1)
        {
            cout << "Edge: " << x << " - " << y << " Cost: " << min << endl;
            minCost += min;
            selected[y] = true;
        }
    }
    
    cout << "\nMinimum Cost of Spanning Tree: " << minCost << endl;
}

int main()
{
	graph f;
    f.create();
    f.display();
    f.prims();
    return 0;
}
