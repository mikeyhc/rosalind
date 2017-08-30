#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $out = `./rosalind-iprb 2 2 2`;
$exit++ if ($out ne "0.783333\n");
$exit++ unless (system("./rosalind-iprb"));
$exit++ unless (system("./rosalind-iprb a 1 2"));
exit $exit;
