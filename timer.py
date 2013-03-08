'''
A simple script to run my program 10,000 times and time it.
'''

from time import time
import random

import numpy
import sh
from sh import echo

if __name__ == '__main__':
    inputs = []
    alu_times = []
    simple_times = []
    alu_command = sh.Command('./alu')
    simple_command = sh.Command('./simple')

    operator = '*'

    for _ in xrange(5000):
        operand1 = str(random.randint(1, 32768))
        operand2 = str(random.randint(1, 32768))
        inputs.append(' '.join([operator, operand1, operand2]))

    for i in inputs:
        begin_time = time()
        alu_command(echo(i))
        end_time = time()
        alu_times.append(end_time - begin_time)

        begin_time = time()
        simple_command(echo(i))
        end_time = time()
        simple_times.append(end_time - begin_time)

    print 'Multiplication:\n'

    print 'Average execution time(alu method): %s seconds' % (numpy.average(alu_times))
    print 'Standard deviation in execution time(alu method): %s seconds' % (numpy.std(alu_times))
    print 'Minimum execution time(alu method): %s seconds' % (min(alu_times))
    print 'Maximum execution time(alu method): %s seconds\n' % (max(alu_times))

    print 'Average execution time(simple method): %s seconds' % (numpy.average(simple_times))
    print 'Standard deviation in execution time(simple method): %s seconds' % (numpy.std(simple_times))
    print 'Minimum execution time(simple method): %s seconds' % (min(simple_times))
    print 'Maximum execution time(simple method): %s seconds\n' % (max(simple_times))


    operator = '/'

    for _ in xrange(5000):
        operand1 = str(random.randint(1, 32768))
        operand2 = str(random.randint(1, 32768))
        inputs.append(' '.join([operator, operand1, operand2]))

    for i in inputs:
        begin_time = time()
        alu_command(echo(i))
        end_time = time()
        alu_times.append(end_time - begin_time)

        begin_time = time()
        simple_command(echo(i))
        end_time = time()
        simple_times.append(end_time - begin_time)

    print 'Division:\n'

    print 'Average execution time(alu method): %s seconds' % (numpy.average(alu_times))
    print 'Standard deviation in execution time(alu method): %s seconds' % (numpy.std(alu_times))
    print 'Minimum execution time(alu method): %s seconds' % (min(alu_times))
    print 'Maximum execution time(alu method): %s seconds\n' % (max(alu_times))

    print 'Average execution time(simple method): %s seconds' % (numpy.average(simple_times))
    print 'Standard deviation in execution time(simple method): %s seconds' % (numpy.std(simple_times))
    print 'Minimum execution time(simple method): %s seconds' % (min(simple_times))
    print 'Maximum execution time(simple method): %s seconds' % (max(simple_times))