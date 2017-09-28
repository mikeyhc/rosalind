#!/usr/bin/perl

use 5.010;
use warnings;
use strict;

my $exit = 0;
my $out = `./rosalind-iev 1 0 0 1 0 1`;
$exit++ if $out ne "3.5\n";
$out = `./rosalind-iev 17694 17964 19355 18338 19724 16114`;
$exit++ if $out ne "157257\n";
$out = `./rosalind-iev 19693 17215 19087 19450 18998 18989`;
$exit++ if $out ne "160163\n";
$exit++ unless system('./rosalind-iev');
$exit++ unless system('./rosalind-iev 0');
$exit++ unless system('./rosalind-iev 0 1');
$exit++ unless system('./rosalind-iev 0 1 2');
$exit++ unless system('./rosalind-iev 0 1 2 3');
$exit++ unless system('./rosalind-iev 0 1 2 3 4');
$exit++ unless system('./rosalind-iev a');
$exit++ unless system('./rosalind-iev 0 b');
$exit++ unless system('./rosalind-iev 0 0 c');
$exit++ unless system('./rosalind-iev 0 0 0 d');
$exit++ unless system('./rosalind-iev 0 0 0 0 e');
$exit++ unless system('./rosalind-iev 0 0 0 0 0 f');
exit $exit;
