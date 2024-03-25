/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:48:47 by martiper          #+#    #+#             */
/*   Updated: 2024/03/25 18:23:05 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_H
# define DATE_H

# include <time.h>
# include <stdbool.h>
# include <stddef.h>

/*
  Date format strings

  TIME:
	%Y: Year with century as a decimal number.
	%m: Month as a decimal number [01,12].
	%d: Day of the month as a decimal number [01,31].
	%H: Hour (24-hour clock) as a decimal number [00,23].
	%I: Hour (12-hour clock) as a decimal number [01,12].
	%k: Hour (24-hour clock) as a decimal number padded with spaces [0,23].
	%l: Hour (12-hour clock) as a decimal number padded with spaces [1,12].
	%M: Minute as a decimal number [00,59].
	%P: Meridian indicator in lowercase [am, pm].
	%p: Meridian indicator in uppercase [AM, PM].
	%s: Seconds since the Epoch.
	%S: Second as a decimal number [00,59].
	%X: ctime(3) [12-19]
	%z: Timezone offset in the form +HHMM or -HHMM.
  DATE:
	%a: Abbreviated weekday name.
	%A: Full weekday name.
	%b: Abbreviated month name.
	%B: Full month name.
	%C: Century as a decimal number [00,99].
	%j: Day of the year as a decimal number [001,366].
	%q: quarter of the year as a decimal number [1,4].
	%u: Day of the week as a decimal number [1,7], with 1 representing Monday.
	%w: Day of the week as a decimal number [0,6], with 0 representing Sunday.
	%y: Year without century as a decimal number [00,99].
  Literals:
	%%: A literal '%' character.
	%n: A newline character.
	%t: A tab character.
  Flags:
	_: pad the field with spaces.
	0: pad the field with zeros.
	+: pad with zeros and a plus sign for positive numbers.
 */

char	*date_format(time_t date, const char *format);

#endif
