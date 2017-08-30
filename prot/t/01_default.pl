#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = "AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA";
my $out = `echo $sample | ./rosalind-prot`;
$exit++ if ($out ne "MAMAPRTEINSTRING\n");
exit $exit;
