### Challenge no. 9 (probably)
So, this challenge will be done a little differently. Last
one i tried to do some external files, some classes, and it
was a little hassle to do it right in the Makefile, and a
bit tiring to manually edit it everytime I add some new
file. When I'll want to make a bigger project, I don't want
to take my mind of the thought process to think about how to
make Makefile work. So, this one will focus mainly on two
things: 
        - Generating a decent Makefile
        - Classes

That would be it. And sice I got my vimrc file somewhat
right, there's no more problem with hopping from one file to
the other, since I helped myself with the tabs and windows.

Let's just jump into it. This challenge is a Love calculator
algorithm. It works like this: I don't frickin know anything
about love calculators. They take letters and spew out a
number, specifically the percentage of love between two
people. I saw one tutorial how it should work, written in
php, and came with something like this - for every letter,
count them in the sentence "A loves B", where A and B are
substituted by given names. Now, when a leter repeats ignore
it. Then, take the leftmost and the rightmost numbers, and
add them. Keep adding them until there's just two or one
numbers, and the number is the percentage. It's a little
foggy for me, because the tutorial was not well written, but
I'll come with something, surely. Now, let's start by
reading about the Makefile.

### The application

Ask user for name A
Ask user for name B

Generate the sentence "A loves B"
Make the sentence lowercase
For each letter:
        Count the number of occurences
        If the the letter was already accounted for:
                Skip
        Save the number string

Until there's one or none numbers in the string:
        Take leftmost and rightmost number and add them
        Append the result into new string
        If one number is left, write it to the new string

Repeat the process until theres only two numbers left

The result of the last cummulation is the result of the app

### The methods

  > char - to lower
  > int  - to char
