#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = ">Rosalind_1\n" .
"ATCCAGCT\n" .
">Rosalind_2\n" .
"GGGCAACT\n" .
">Rosalind_3\n" .
"ATGGATCT\n" .
">Rosalind_4\n" .
"AAGCAACC\n" .
">Rosalind_5\n" .
"TTGGAACT\n" .
">Rosalind_6\n" .
"ATGCCATT\n" .
">Rosalind_7\n" .
"ATGGCACT\n";
my $out = `/bin/echo -e "$sample" | ./rosalind-cons`;
$exit++ if ($out ne "ATGCAACT\n" .
"A: 5 1 0 0 5 5 0 0\n" .
"C: 0 0 1 4 2 0 6 1\n" .
"G: 1 1 6 3 0 1 0 0\n" .
"T: 1 5 0 0 0 1 1 6\n");
exit $exit;
