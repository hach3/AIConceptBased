# AIConceptBased [![Build Status](https://travis-ci.org/SherlockStd/AIConceptBased.svg?branch=master)](https://travis-ci.org/SherlockStd/AIConceptBased)

The concepts are composed by a name and associated words. For example, the concept of "me" is composed of words "I, me, my, mine". 
Once I extracted the concepts of a sentence, I can create connections between them to formatate sentences.

It's a console based program written in C++ right now.

## Build & Run

```bash
make && ./AIv2.3
```

## Available sentences :


Only question are allowed atm.

### WH + Be + S

#### Examples :

What are you ?

who are you ?

Where am I ?

...


### WH + Be + S + C

#### Examples :

What is your name ? : The subject is supposed to be "your name", but i just extract "your" as the subject and turn "name" as complement

What is your car ?

What is my name ?...

You can check which answers is known by checking in memory.cpp. The init function creates all "souvenirs".


### To add a souvenir :
```c++
this->addSouvenir("CONCEPT_VERB", "CONCEPT_NAME", "WHO", "WHY", "WHERE", "WHEN", "WHAT", "HOW", BOOL IS, BOOL HAVE);
```
The booleans are still on working :p


#### Example :

```c++
this->addSouvenir("CONCEPT_BE", "CONCEPT_NAME", "I", dunnowhy, dunnowhere, dunnowhen, "Gandalf", dunnohow, true, true);
```

We just created a souvenir of having a name, and its value.


Concepts are structures (check concept.h) of words category. Words can be name, subject, etc...


## @TODO :

- Copy the "And You ?" function From previous version


- Add a vector2 of linking concepts to concept.

	The concept car is related to the concept of mecanic, road, etc...
	
	That allows to the next to create a discussion around a topic.
	

- Handle more sentence structures
