'use strict';


// function CustomReturn (left,right,down,up){
//     CustomReturn.prototype.left = left;
//     CustomReturn.prototype.right = right;
//     CustomReturn.prototype.up = up;
//     CustomReturn.prototype.down = down;
// }

// let a = new CustomReturn(1,2,3,4);
// console.log(CustomReturn.prototype.right);


// class customReturn {
//     constructor(left, right, up, down) {
//         this.left = left;
//         this.right = right;
//         this.up = up;
//         this.down = down;
//     }
// }


/**
 * @param {number[][]} grid
 * @return {number}
 */
var closedIsland = function (grid) {
    //make visited array
    let visited = new Array(grid.length).fill().map(() => {
        return new Array(grid[0].length).fill(false);
    })
    //now we call bfs on every component, check if valid component or not
    let ans = 0;
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (visited[i][j] == false && grid[i][j] == 0) {
                let isValid = bfs(visited, grid, i, j);
                ans += (isValid) ? 1 : 0;
            }
        }
    }
    return ans;
};

/**
 * 
 * @param {number[][]} visited 
 * @param {number[][]} grid 
 * @param {number} i 
 * @param {number} j 
 */
let bfs = (visited, grid, i, j) => {
    let q = [];
    q.push([i, j]);
    let topMost = i, bottomMost = i;
    let leftMost = j, rightMost = j;
    while (q.length > 0) {
        let current = q.shift();
        visited[current[0]][current[1]] = true;
        topMost = Math.min(current[0], topMost);
        bottomMost = Math.max(bottomMost, current[0]);
        leftMost = Math.min(leftMost, current[1]);
        rightMost = Math.max(current[1], rightMost);
        for (let a = 0; a < xdir.length; a++) {
            let x = xdir[a] + current[0];
            let y = ydir[a] + current[1];
            if (x >= 0 && y >= 0 && x < grid.length && y < grid[0].length && grid[x][y] == 0 && visited[x][y] == false) {
                q.push([x, y]);
            }
        }
    }
    if (leftMost > 0 && rightMost < grid[0].length - 1) {
        if (topMost > 0 && bottomMost < grid.length - 1) {
            return true;//valid as it is surrounded
        }
    } else {
        return false;
    }
}


let xdir = [0, 0, 1, -1];
let ydir = [1, -1, 0, 0];

//let grid = [[1, 1, 1, 1, 1, 1, 1, 0], [1, 0, 0, 0, 0, 1, 1, 0], [1, 0, 1, 0, 1, 1, 1, 0], [1, 0, 0, 0, 0, 1, 0, 1], [1, 1, 1, 1, 1, 1, 1, 0]];
//let grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]];
let grid = [[1, 1, 1, 1, 1, 1, 1], [1, 0, 0, 0, 0, 0, 1], [1, 0, 1, 1, 1, 0, 1], [1, 0, 1, 0, 1, 0, 1], [1, 0, 1, 1, 1, 0, 1], [1, 0, 0, 0, 0, 0, 1], [1, 1, 1, 1, 1, 1, 1]]
console.log(closedIsland(grid));