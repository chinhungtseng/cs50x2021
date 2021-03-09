from cs50 import get_string


def get_text():
    """Prompt user for text. If user enter empty string,
    then prompt again."""
    while True:
        string = get_string("Text: ")
        if string != "":
            return string


def text_parser(text):
    """Helper function for parse input text."""
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    return letters, words, sentences


def count_letters(text):
    """Count the number of letters from input text."""
    return len([c for c in text if c.isalnum()])


def count_words(text):
    """Count the number of words from input text."""
    return len([w for w in text.split(' ') if w != ""])


def count_sentences(text):
    """Count the number of sentences from input text."""
    return len([w for w in text.replace('? ', '. ').split('.') if w != ""])


def coleman_liau_index(letters, words, sentences):
    """Coleman-Liau index formula. where L is the average number of letters
    per 100 words in the text, and S is the average number of sentences per
    100 words in the text."""
    L = float(letters) / words * 100.0
    S = float(sentences) / words * 100.0

    return round(0.0588 * L - 0.296 * S - 15.8)


def print_grade(grade):
    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")


def main():
    text = get_text()
    letters, words, sentences = text_parser(text)
    grade = coleman_liau_index(letters, words, sentences)
    print_grade(grade)


if __name__ == "__main__":
    main()