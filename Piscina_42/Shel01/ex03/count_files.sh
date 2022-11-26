#!/bin/bash

find . -print | awk 'END {print NR}'
