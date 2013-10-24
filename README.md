tiles
=====

a problem given to me at the google onsite interview.

Its a quick rundown which uses a single stack to maintain
the finds.

If I were to finish it to build names, I would build a second stack
and pop the results and push onto it.  Then I would pop off that stack in order counting the letters.  So for things like Cone which gives two results, it 
would print
CONe sol1
CoNe sol2.

Also I am not really worried about trying to optimize some of the return codes,
since I'm going for clarity.  The tables could be built using a more generalized
hash table with links for letters.  In fact, I was originally thinking of making a table of 256 entries where the ASCII value would be the key into the table and then the linked list would store all variants for that letter.  Something like this:

H is key, He->Hg

But it was simpler to just made a two dimensional array so it is something like
this

[H]: [E]=1 [G]=1


Unit tests were a boilerplate of code.  I was not overly worried with something
like rc=ok if ok then rc=ok.

