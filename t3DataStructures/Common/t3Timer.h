#ifndef T3_TIMER_H
#define T3_TIMER_H

class t3Timer
{
public:
    t3Timer():startTime(0.0f){}

    // start counting time
    double start();

	// end counting time
    double end();

	// difference of counting time between start and end
    double difference();

    double startTime, endTime;
};

#endif