# Producer Consumer Paradigm in C

The goal of this short project is to use shell memories 
to handle producer consumer problem in C. 

The following describes the 3 files to implement the paradigm. 

_main.c_ implements the distribution of work between producer and consumer using vfork

_Producer.c_ implements the producer function, which reads one character at a time from *mydata.txt*. 

_Consumer.c_ implements the consumer function which displays to screen all characters retrived from the producer. 
