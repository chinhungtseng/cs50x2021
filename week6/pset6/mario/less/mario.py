from cs50 import get_int


def get_height(min=1, max=8):
    """Prompt user for height value."""
    while True:
        height = get_int("Height: ")
        if height >= min and height <= max:
            return height


def print_pyramid(n):
    """Print n height of half-pyramid to console."""
    for i in range(1, n+1):
        print(" "*(n-i) + "#"*i)


def main():
    height = get_height()
    print_pyramid(height)


if __name__ == "__main__":
    main()
