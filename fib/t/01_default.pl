#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $out = `./rosalind-fib 5 3`;
$exit++ if $out ne "19\n";
$exit++ unless system('./rosalind-fib');
$exit++ unless system('./rosalind-fib a b');
