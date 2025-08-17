from functools import lru_cache

class Solution:
    def maxChocolates(self, grid):
        row, col = len(grid), len(grid[0])

        @lru_cache(None)
        def dp(i, j1, j2):
            # Out of bounds
            if j1 < 0 or j1 >= col or j2 < 0 or j2 >= col:
                return -10**8

            # Last row
            if i == row - 1:
                if j1 == j2:
                    return grid[i][j1]
                return grid[i][j1] + grid[i][j2]

            maxi = -10**8
            # Try all 9 moves
            for dj1 in (-1, 0, 1):
                for dj2 in (-1, 0, 1):
                    if j1 == j2:
                        value = grid[i][j1]
                    else:
                        value = grid[i][j1] + grid[i][j2]
                    value += dp(i+1, j1+dj1, j2+dj2)
                    maxi = max(maxi, value)

            return maxi

        # Robots start at (0,0) and (0, col-1)
        return dp(0, 0, col-1)


def main():
    # Example input
    grid = [
        [3, 1, 1],
        [2, 5, 1],
        [1, 5, 5],
        [2, 1, 1]
    ]

    sol = Solution()
    print("Maximum chocolates collected:", sol.maxChocolates(grid))


if __name__ == "__main__":
    main()
