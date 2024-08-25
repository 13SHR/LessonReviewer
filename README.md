
# LessonReviewer

This is a reviewer based on a word list. It randomly chooses one word on one line, and asks for the whole line in order, separated by returns. The first wrong word of the line stops the input, and displays the correction.

## Usage

<p>Clone the repository, create a list <em>(if you don't want to learn the English irregular verbs translated in French)</em>, and run </p>

```gcc main.c -O1 -o lesson_review; ./lesson_review```

<p></p>Then enter the file name of the list. </p>

***

<p>The words must be separated by <strong>tabs</strong> on each line, and there must not be a blank line at the end of the file.</p>

## Requirements

`gcc` or any C compiler must be installed

## Example

I put an example `list.txt`, containing the irregular verbs list from [verbesirreguliersanglais.com](https://verbesirreguliersanglais.com/) to show how to format the input.
