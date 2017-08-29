#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAG"
    . "AGTGTCTGATAGCAGC";
my $out = `echo $sample | ./rosalind-dna`;
$exit++ if ($out ne "20 12 17 21\n");
$exit++ unless (system("echo 0 | ./rosalind-dna"));
exit $exit;
