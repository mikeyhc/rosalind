#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = "GAGCCTACTAACGGGAT\n".
    "CATCGTAATGACGGCCT\n";
my $out = `echo -e \"$sample\" | ./rosalind-hamm`;
$exit++ if ($out ne "7\n");
exit $exit;
