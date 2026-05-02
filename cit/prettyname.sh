#!/bin/sh
grep "PRETTY_NAME=" /etc/os-release | cut -d'"' -f2
