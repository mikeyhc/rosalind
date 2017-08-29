#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = "GATGGAACTTGACTACGTAAATT";
my $out = `echo $sample | ./rosalind-rna`;
$exit++ if ($out ne "GAUGGAACUUGACUACGUAAAUU\n");
$exit++ unless (system("echo 0 | ./rosalind-rna"));
exit $exit;
