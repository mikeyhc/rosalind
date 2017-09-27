#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = ">Rosalind_0498\n" .
    "AAATAAA\n" .
    ">Rosalind_2391\n" .
    "AAATTTT\n" .
    ">Rosalind_2323\n" .
    "TTTTCCC\n" .
    ">Rosalind_0442\n" .
    "AAATCCC\n" .
    ">Rosalind_5013\n" .
    "GGGTGGG\n";
my $out = `/bin/echo -e "$sample" | ./rosalind-grph`;
print($out);
$exit++ if ($out ne "Rosalind_0498 Rosalind_2391\n" .
    "Rosalind_0498 Rosalind_0442\n" .
    "Rosalind_2391 Rosalind_2323\n");
exit $exit;
