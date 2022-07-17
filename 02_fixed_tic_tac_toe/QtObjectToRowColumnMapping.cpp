#include "QtObjectToRowColumnMapping.h"

void QtObjectToRowColumnMapping::addMapping(
    QObject* button,
    unsigned int row,
    unsigned int column
) {
    RowColumn rc;
    rc.row = row;
    rc.column = column;
    m_mappings.insert({button, rc});
}

RowColumn QtObjectToRowColumnMapping::getMapping(QObject* button) {
    return m_mappings.at(button);
}
