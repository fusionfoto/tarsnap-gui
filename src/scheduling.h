#ifndef SCHEDULING_H
#define SCHEDULING_H

#include <QObject>
#include <QWidget>

enum schedulestatus
{
    SCHEDULE_OK,
    SCHEDULE_ERROR,
    SCHEDULE_NEED_INFO
};

struct scheduleinfo
{
    schedulestatus status;
    QString        message;
    QString        extra;
};

struct scheduleinfo launchdEnable();
struct scheduleinfo launchdDisable();
struct scheduleinfo cronEnable();
struct scheduleinfo cronEnable_p2(QString cronBlock, QString currentCrontab);
struct scheduleinfo cronDisable();
struct scheduleinfo cronDisable_p2(QString linesToRemove,
                                   QString currentCrontab);

/*!
 * \ingroup Misc
 * \brief The Scheduling QObject handles scheduling tasks.
 */
class Scheduling : public QObject
{
    Q_OBJECT

public:
    //! Constructor.
    Scheduling(QWidget *parent = nullptr);
    ~Scheduling();

    //! Check and update (if necessary) the path to the Tarsnap-GUI binary
    //!   \return -1 no change occurred
    //!   \return 0 executable path was corrected
    //!   \return 1 error
    static int correctedSchedulingPath();

public slots:
    //! Set up launchd or cron jobs
    void enableJobScheduling();
    //! Disable launchd or cron jobs
    void disableJobScheduling();

private:
    QWidget *parent;
};

#endif
