#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = "AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA";
my $out = `echo $sample | ./rosalind-prot`;
$exit++ if ($out ne "MAMAPRTEINSTRING\n");
$exit++ unless system("echo xyz | ./rosalind-prot");
$exit++ unless system("echo Ayz | ./rosalind-prot");
$exit++ unless system("echo AAz | ./rosalind-prot");
exit $exit;
