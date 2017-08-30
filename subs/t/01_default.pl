#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = "GATATATGCATATACTT\nATAT";
my $out = `/bin/echo -e "$sample" | ./rosalind-subs`;
$exit++ if ($out ne "2 4 10 \n");
exit $exit;
