#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $sample = ">Rosalind_6404\n" .
"CCTGCGGAAGATCGGCACTAGAATAGCCAGAACCGTTTCTCTGAGGCTTCCGGCCTTCCC\n" .
"TCCCACTAATAATTCTGAGG\n" .
">Rosalind_5959\n" .
"CCATCGGTAGCGCATCCTTAGTCCAATTAAGTCCCTATCCAGGCGCTCCGCCGAAGGTCT\n" .
"ATATCCATTTGTCAGCAGACACGC\n" .
">Rosalind_0808\n" .
"CCACCCTCGTGGTATGGCTAGGCATTCAGGAACCGGAGAACGCTTCAGACCAGCCCGGAC\n" .
"TGGGAACCTGCGGGCAGTAGGTGGAAT\n";
my $out = `echo -e "$sample" | ./rosalind-gc`;
$exit++ if ($out ne "Rosalind_0808\n60.919540\n");
exit $exit;
