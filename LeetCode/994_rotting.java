class Solution {
    public static final int[][] ADJACENT_4 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	private Queue<Point> Q = new LinkedList<Point>();
	private int totalFresh = 0;
	private int row = 0, col = 0;
	
	private List<Point> initialRottenPositions(int[][] grid) {
		List<Point> positions = new ArrayList<Point>();
		row = grid.length;
		col = grid[0].length;
		
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(grid[i][j] == 2) {
					positions.add(new Point(i, j));
				} else if(grid[i][j] == 1) {
					totalFresh++;
				}
			}
		}
		return positions;
	}
	
	private boolean withinGrid(int x, int y) {
		return x >= 0 && x < row && y >= 0 && y < col;
	}
	
	private int bfs(int[][] grid) {
		int min = 0;
		totalFresh = 0;
		Q = new LinkedList<Point>();
		List<Point> initRot = initialRottenPositions(grid);
		
		if(totalFresh == 0) return 0;
		if(initRot.size() == 0) return -1;
		
		Q.addAll(initRot);
		
		while(!Q.isEmpty()) {
			int length = Q.size();
			
			boolean found = false;
			
			for(int i = 0; i < length; i++) {
				Point point = Q.poll();
				
				if(point == null) continue;
				
				for(int j = 0; j < 4; j++) {
					int x = point.x + ADJACENT_4[j][0];
					int y = point.y + ADJACENT_4[j][1];
					
					if(withinGrid(x, y) && grid[x][y] == 1) {
						grid[x][y] = 2;
						totalFresh--;
						Q.add(new Point(x, y));
						
						if(found == false) {
							min++;
						}
						found = true;
					}
				}
				
			}
		}
		
		return totalFresh == 0 ? min : -1;
		
	}
	
	public int orangesRotting(int[][] grid) {
		int min = bfs(grid);
		
		return min;
    }
	
	private static class Point {
		int x, y;
		
		Point(int a, int b) {
			x = a;
			y = b;
		}
	}
}