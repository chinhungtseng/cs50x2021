def greeting():
    """Prompts a user for their name,
    and then prints hello, so-and-so."""
    answer = input("What is your name?\n")
    print(f"hello, {answer}")


def main():
    greeting()


if __name__ == "__main__":
    main()