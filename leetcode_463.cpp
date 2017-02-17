// island perimeter

// math problem  4*island-2*neighbour(down or right)
#include <iostream>
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
	int island=0,neighbour=0;
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[i].size();j++){
			if(grid[i][j] == 1){
				island++;
				if(i<grid.size()-1 && grid[i+1][j] == 1) neighbour++;
				if(j<grid[i].size()-1 && grid[i][j+1] == 1) neighbour++;
			}
		}
	}
	return 4*island-2*neighbour;
}

int main(){
	vector<vector<int>> a={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
	cout << islandPerimeter(a) << endl;
	return 0;
}