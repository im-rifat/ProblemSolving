class Solution {
    public static final int[][] ADJACENT_4 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
	private byte[][] flag;
	private int row, col;
	private Queue<Point> Q;
	
	private boolean withinGrid(int x, int y, int row, int col) {
		return x >= 0 && x < row && y >= 0 && y < col;
	}
	
	private List<Point> getAllCornersO(char[][] board) {
		List<Point> list = new ArrayList<Point>();
		
		for(int i = 0; i < col; i++) {
			if(board[0][i] == 'O') list.add(new Point(0, i));
			if(board[row - 1][i] == 'O') list.add(new Point(row - 1, i));
		}
		
		for(int i = 0; i < row; i++) {
			if(board[i][0] == 'O') list.add(new Point(i, 0));
			if(board[i][col - 1] == 'O') list.add(new Point(i, col - 1));
		}
		
		return list;
	}
	
	private void bfs(char[][] board) {
		List<Point> list = getAllCornersO(board);
		Q = new LinkedList<Point>();
		Q.addAll(list);
		
		while(!Q.isEmpty()) {
			Point p = Q.poll();
			
			flag[p.x][p.y] = 3;
			
			for(int i = 0; i < 4; i++) {
				int x = p.x + ADJACENT_4[i][0];
				int y = p.y + ADJACENT_4[i][1];
				
				if(withinGrid(x, y, row, col) && board[x][y] == 'O' && flag[x][y] == 1 ) {
					Q.add(new Point(x, y));
				}
			}
		}
		
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(flag[i][j] != 3) {
					board[i][j] = 'X';
				}
			}
		}
	}
	
	private void printBoard(char[][] board) {
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				System.out.printf("%c", board[i][j]);
			}
			System.out.print("\n");
		}
	}
	
	public void solve(char[][] board) {
		if(board == null || board.length == 0) return;
		
		row = board.length;
		col = board[0].length;
		
		flag = new byte[row][col];
		
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(board[i][j] == 'O') {
					flag[i][j] = 1;
				} else {
					flag[i][j] = 2;
				}
			}
		}
		
		bfs(board);
		
		//printBoard(board);
    }
	
	private static class Point {
		int x, y;
		
		Point(int a, int b) {
			x = a;
			y = b;
		}
	}
}