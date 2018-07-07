
# log

[![Last release](https://img.shields.io/github/tag/LeakyAbstractions/log.svg?label=release&colorB=007ec6)](https://github.com/LeakyAbstractions/log/releases)
[![Build status](https://travis-ci.org/LeakyAbstractions/log.svg?branch=master)](https://travis-ci.org/LeakyAbstractions/log)
[![Code coverage](https://codecov.io/github/LeakyAbstractions/log/coverage.svg?branch=master)](https://codecov.io/github/LeakyAbstractions/log?branch=master)
[![Static analysis](https://scan.coverity.com/projects/14165/badge.svg)](https://scan.coverity.com/projects/leakyabstractions-log)

> Write program logs

![](https://github.com/LeakyAbstractions/log/raw/master/doc/logo.png)


## A tiny C logging library

Generate customized logs to files and other destinations.

> This software adheres to [Pragmatic Versioning](https://pragver.github.io/).


## API


### Types

- `log_event`: Represents a logging event
- `log_context`: Represents the logging context of a specific source file
- `log_logger`: Dispatches logging events through its appender
- `log_config`: Represents the configuration of a logging context
- `log_config_type`: Represents a type of logging configurations
- `log_appender`: Delivers logging events and outputs them to their destination
- `log_appender_type`: Represents a type of appenders
- `log_layout`: Transforms logging events and outputs them to a specific stream
- `log_layout_type`: Represents a type of layouts


### Functions

- `log_event_new`: Creates a new logging event and delivers it to the loggers configured in the current logging context
- `log_config_initialize`: Initializes the specified logging configuration
- `log_config_finalize`: Finalizes the specified logging configuration
- `log_loggers_initialize`: Initializes a list of loggers
- `log_loggers_finalize`: Finalizes a list of loggers


## Author

Copyright 2018 [Guillermo Calvo](https://github.com/guillermocalvo)

[![](https://resume.guillermo.in/assets/images/thumb.png)](https://guillermo.in/)


## License

This is free software: you can redistribute it and/or modify it under the terms
of the **GNU Lesser General Public License** as published by the
*Free Software Foundation*, either version 3 of the License, or (at your option)
any later version.

This software is distributed in the hope that it will be useful, but
**WITHOUT ANY WARRANTY**; without even the implied warranty of
**MERCHANTABILITY** or **FITNESS FOR A PARTICULAR PURPOSE**. See the
[GNU Lesser General Public License](http://www.gnu.org/licenses/lgpl.html) for
more details.

You should have received a copy of the GNU Lesser General Public License along
with this software. If not, see <http://www.gnu.org/licenses/>.

### Required

- **License and copyright notice**: Include a copy of the license and copyright
notice with the code.
- **Library usage**: The library may be used within a non-open-source
application.
- **Disclose Source**: Source code for this library must be made available when
distributing the software.

### Permitted

- **Commercial Use**: This software and derivatives may be used for commercial
purposes.
- **Modification**: This software may be modified.
- **Distribution**: You may distribute this software.
- **Sublicensing**: You may grant a sublicense to modify and distribute this
software to third parties not included in the license.
- **Patent Grant**: This license provides an express grant of patent rights from
the contributor to the recipient.

### Forbidden

- **Hold Liable**: Software is provided without warranty and the software
author/license owner cannot be held liable for damages.
