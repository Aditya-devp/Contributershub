public class sudokusolver {
    public static void main(String[] args) {
    int[][] board={{5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}};
    if(solve(board)){
        display(board);
    }
    else
        System.out.println("Sudoko cannot be solved!");
    }
    static boolean solve(int[][] board){
        int n= board.length;
        int r=-1;
        int c=-1;
        boolean emptyleft=true;

        //this is how we are replacing the r,c from arguments
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==0){
                    r=i;
                    c=j;
                    emptyleft=false;
                    break;//one potential ans so break
                }
            }
            //if you found some empty element in row then break
            if(emptyleft==false)
                break;
        }
        if(emptyleft==true)
            return true;//sudoku solved

        //move to backtarcking part
        for(int number=1;number<=9;number++){
            if(isSafe(board,r,c,number)) {
                board[r][c] = number;
                if (solve(board))//found the ans
                    return true;
                else {
                    //backtrack
                    board[r][c] = 0;
                }
            }
        }
        return false;
    }
    private static void display(int[][] board){
        for(int[] row:board){
            for(int num:row){
                System.out.print(num+" ");
            }
            System.out.println();
        }
    }
    static boolean isSafe(int[][] board,int row,int col,int num){
        //check the row,so run a for loop
        for(int i=0;i<board.length;i++){
            if(board[row][i]==num)
                return false;
        }
        //check the cols,so another for loop
        for(int[] nums:board){
            //check if nums is in column
            if(nums[col]==num)
                return false;
        }
        //check the boxes
        int sqrt=(int)(Math.sqrt(board.length));
        int rowstart=row-row%sqrt;
        int colstart=col-col%sqrt;
        for(int i=rowstart;i<rowstart+sqrt;i++){
            for(int j=colstart;j<colstart+sqrt;j++){
                if(board[i][j]==num)
                    return false;
              }
        }
        return true;
    }
}
