#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = ">Rosalind_1\n" .
    "GATTACA\n" .
    ">Rosalind_2\n" .
    "TAGACCA\n" .
    ">Rosalind_3\n" .
    "ATACA\n";
my $out = `/bin/echo -e "$sample" | ./rosalind-lcsm`;
$exit++ if ($out ne "TA\n");
exit $exit;
