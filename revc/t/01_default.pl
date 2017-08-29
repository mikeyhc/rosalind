#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = "AAAACCCGGT";
my $out = `echo $sample | ./rosalind-revc`;
$exit++ if ($out ne "ACCGGGTTTT\n");
$exit++ unless (system("echo 0 | ./rosalind-revc"));
exit $exit;
