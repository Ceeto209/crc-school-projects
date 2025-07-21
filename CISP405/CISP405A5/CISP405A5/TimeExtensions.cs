// Name: Israel Vasquez
// Assignment#: A5
// File Name: TimeExtensions.cs
// Purpose: This static class contains extension methods for the Time1 class.
// Course: CISP 405 SU25

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public static class TimeExtensions
{
    // Increments the time by one second.
    public static void Tick(this Time1 time)
    {
        time.Second++;
        if (time.Second > 59)
        {
            time.Second = 0;
            time.IncrementMinute();
        }
    }

    // Increments the time by one minute.
    public static void IncrementMinute(this Time1 time)
    {
        time.Minute++;
        if (time.Minute > 59)
        {
            time.Minute = 0;
            time.IncrementHour();
        }
    }

    // Increments the time by one hour.
    public static void IncrementHour(this Time1 time)
    {
        time.Hour++;
        if (time.Hour > 23)
        {
            time.Hour = 0;
        }
    }

    // Increments the time by a specified number of seconds.
    public static void Tick(this Time1 time, int secondsToAdd)
    {
        for (int i = 0; i < secondsToAdd; i++)
        {
            time.Tick();
        }
    }
}
