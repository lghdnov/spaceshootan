#include <string>
#include <ostream>
#include <list>
#include <utility>
#include <vector>
#include <ctime>

using namespace std;

namespace logz{

    enum LoggerSens{
        ERROR, INFO, DEBUG
    };

    class ILogModifier{
    public:
        virtual void init(const string& title, LoggerSens sens) = 0;
        virtual void apply(const string& message, ostream& output, LoggerSens sens) = 0;
    };

    static vector<ostream*> global_outs;

    class TitleModifier : public ILogModifier {
    public:
        std::string title;

        void init(const string& title, LoggerSens sens) override {
            this->title = title;
        }

        void apply(const string& message, ostream& output, LoggerSens messageSens) override {
            output << "[" << title << "] : ";
        }
    };

    class SensModifier : public ILogModifier {
    public:
        static char err_str[], inf_str[], dbg_str[];
        void init(const string& title, LoggerSens sens) override {}

        void apply(const string& message, ostream& output, LoggerSens messageSens) override {
            switch (messageSens) {
                case ERROR: output << err_str; break;
                case INFO: output << inf_str; break;
                case DEBUG: output << dbg_str; break;
            }
            output << " ";
        }
    };
    inline char SensModifier::err_str[] = "[ERROR]";
    inline char SensModifier::inf_str[] = "[INFO]";
    inline char SensModifier::dbg_str[] = "[DEBUG]";

    class TimeModifier : public ILogModifier {
    public:

        void init(const string& title, LoggerSens sens) override {}

        void apply(const string& message, ostream& output, LoggerSens messageSens) override {
            time_t currentTime = time(nullptr);
            tm* lt = localtime(&currentTime);

            output << lt->tm_hour << ":" << lt->tm_min << ":" << lt->tm_sec << " ";
        }
    };

    class MessageModifier : public ILogModifier {
    public:

        void init(const string& title, LoggerSens sens) override {}

        void apply(const string& message, ostream& output, LoggerSens messageSens) override {
            output << message << " ";
        }
    };

    class Logger{
    private:
        string title;
        vector<ostream*> outputs;
        LoggerSens sens = LoggerSens::DEBUG;
        vector<ILogModifier*> modifiers;

        void to_outputs(const string& message, LoggerSens messageSens){
            for (const auto &ostream_: outputs){
                for (const auto &modifier: modifiers){
                    modifier->apply(message, *ostream_, messageSens);
                }
                *ostream_ << endl;
            }
        }

    public:
       Logger(string title_, vector<ostream*> outputs_):
       title(std::move(title_)), outputs(std::move(outputs_)){}

        void add(ostream* ostream_){
            outputs.push_back(ostream_);
        }

        static void addGlobalOut(ostream* ostream_){
            global_outs.push_back(ostream_);
        }

        vector<ILogModifier*>& getModifiers(){
            return modifiers;
        }

        void initModifier(ILogModifier* modifier){
            modifier->init(title, sens);
        }

        void setSense(LoggerSens sens){
            this->sens = sens;
        }

        void error(const string& message){
            to_outputs(message, LoggerSens::ERROR);
        }

        void info(const string& message){
            if (sens == LoggerSens::ERROR) return;
            to_outputs(message, LoggerSens::INFO);
        }

        void debug(const string& message){
            if (sens != LoggerSens::DEBUG) return;
            to_outputs(message, LoggerSens::DEBUG);
        }
    };

    class LoggerBuilder{
    private:
        Logger* logger;

    public:

        explicit LoggerBuilder(Logger *logger) : logger(logger) {}

        static LoggerBuilder* newLogger(const string& title){
            vector<ostream*> outputs;
            auto logger = new Logger(title, outputs);
            return new LoggerBuilder(logger);
        }

        LoggerBuilder* setSens(LoggerSens sens){
            logger->setSense(sens);
            return this;
        }

        LoggerBuilder* addOut(ostream* ostream_){
            logger->add(ostream_);
            return this;
        }

        LoggerBuilder* addModifier(ILogModifier* modifier){
            logger->initModifier(modifier);
            logger->getModifiers().push_back(modifier);

            return this;
        }

        LoggerBuilder* addStandardModifiers(){

            addModifier(new TimeModifier());
            addModifier(new SensModifier());
            addModifier(new TitleModifier());
            addModifier(new MessageModifier());

            return this;
        }

        Logger* getLogger(){
            if (logger->getModifiers().empty())
                addStandardModifiers();

            for (const auto &out: global_outs){
                logger->add(out);
            }

            return logger;
        }
    };
}