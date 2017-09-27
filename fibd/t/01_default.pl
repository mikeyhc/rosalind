#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $out = `./rosalind-fibd 6 3`;
$exit++ if ($out ne "4\n");
$out = `./rosalind-fibd 96 17`;
$exit++ if ($out ne "51159459138167757395\n");
$exit++ unless (system("./rosalind-fibd abc"));
$exit++ unless (system("./rosalind-fibd 2 xyz"));
$exit++ unless (system("./rosalind-fibd abc 2"));
exit $exit;
