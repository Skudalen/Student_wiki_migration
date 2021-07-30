---
title: named-entity
---

# Named Entities

## Goals

  - Be able to recognize unknown named entities
  - Create a manually annotated training set from speech transcripts
  - Propose an annotation schema

## Plan

  - Convert speech transcripts into a training set
  - Train and evaluate classifier
  - Establish manual annotation 
  - Select unannotated data 

### Data preparation

Input: Transcriber transcripts with inconsistent annotations

``` 
 * First small letter: regular word
 * Capital: named entity
 * ''^^'': faoreign word
 * ''@'': noise
 * ''_'': multi word expression
 * ''/'': pronuncation
```

Output: A file that can be read by `spacy convert`

## People

Cesar Abascal Gutierrez <cesarbielva1994@gmail.com>

## Tools

``` 
 * Machine learning : https://spacy.io/usage/training
 * Manual Annotation : https://prodi.gy/
```
