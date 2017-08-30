#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = "GAGCCTACTAACGGGAT\n".
    "CATCGTAATGACGGCCT\n";
my $out = `/bin/echo -e \"$sample\" | ./rosalind-hamm`;
print "$out";
$exit++ if ($out ne "7\n");
exit $exit;
